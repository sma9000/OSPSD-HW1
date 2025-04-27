import sys
import pandas as pd
import re
from html import escape
import csv  # This is the correct import for CSV constants

print("Running save_emails.py")

sys.path.append("mail-client/mail_gmail_impl/src")
sys.path.append("mail-client/mail_api/src")

try:
    from mail_gmail_impl.gmail_client import GmailClient
    print("GmailClient imported successfully")
except Exception as e:
    print(f"Import failed: {e}")
    sys.exit(1)

def clean_email_content(text):
    """
    Cleans email content for proper CSV formatting:
    1. Removes newlines and extra whitespace
    2. Escapes special characters
    3. Truncates very long emails
    """
    if not text:
        return ""
    
    # Convert to string if not already
    text = str(text)
    
    # Remove HTML tags and special characters
    text = re.sub(r'<[^>]+>', ' ', text)  # Remove HTML tags
    text = re.sub(r'\s+', ' ', text)      # Collapse whitespace
    text = text.strip()                    # Trim whitespace
    
    # Escape CSV problematic characters
    text = text.replace('"', "'")          # Replace double quotes with single
    text = text.replace('\r', ' ')         # Remove carriage returns
    text = text.replace('\n', ' ')         # Replace newlines with spaces
    
    # Truncate very long emails to prevent parsing issues
    return text[:5000]  # Keep first 5000 characters

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

    # Create DataFrame and save with proper CSV formatting
    df = pd.DataFrame(emails)
    
    # CORRECTED LINE: Use csv.QUOTE_MINIMAL instead of pd.csv.QUOTE_MINIMAL
    df.to_csv("emails.csv", 
              index=False, 
              quoting=csv.QUOTE_MINIMAL,  # Changed from pd.csv to csv
              escapechar='\\')
    
    print("Successfully saved clean emails.csv")

if __name__ == "__main__":
    try:
        save_emails_to_csv()
    except Exception as e:
        print(f"Error during execution: {e}")
        sys.exit(1)
