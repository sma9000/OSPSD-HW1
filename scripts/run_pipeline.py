#!/usr/bin/env python3

import sys
import os
import pandas as pd
import re
from html import escape
import csv
import shutil

print("Running run_pipeline.py")

# CI fallback: use sample_emails.csv instead of Gmail
if os.getenv("CI", "false").lower() == "true":
    print("CI environment detected.")
    if os.path.exists("sample_emails.csv"):
        print("Found sample_emails.csv — using it as emails.csv.")
        shutil.copy("sample_emails.csv", "emails.csv")
        print("emails.csv copied successfully.")
        sys.exit(0)
    else:
        print("sample_emails.csv not found in CI. Exiting with error.")
        sys.exit(1)

# Attempt GmailClient import (local/dev use case)
sys.path.append("mail-client/mail_gmail_impl/src")
sys.path.append("mail-client/mail_api/src")

try:
    from mail_gmail_impl.gmail_client import GmailClient
    print("GmailClient imported successfully")
except Exception as e:
    print(f"Import failed: {e}")
    sys.exit(1)

# Email cleaning logic
def clean_email_content(text):
    if not text:
        return ""
    text = str(text)
    text = re.sub(r'<[^>]+>', ' ', text)
    text = re.sub(r'\s+', ' ', text)
    text = text.strip()
    text = text.replace('"', "'")
    text = text.replace('\r', ' ')
    text = text.replace('\n', ' ')
    return text[:5000]

# Fetch emails and save to CSV
def save_emails_to_csv():
    client = GmailClient()
    print("Created GmailClient")

    emails = []
    for message in client.get_messages():
        print(f"Processing message: {message.id}")
        emails.append({
            "mail_id": message.id,
            "email_body": clean_email_content(message.body)
        })

    print(f"Total emails processed: {len(emails)}")

    df = pd.DataFrame(emails)
    df.to_csv("emails.csv", index=False, quoting=csv.QUOTE_MINIMAL, escapechar='\\')
    print("Successfully saved clean emails.csv")

# Entrypoint
if __name__ == "__main__":
    try:
        save_emails_to_csv()
    except Exception as e:
        print(f"Error during execution: {e}")
        sys.exit(1)
