import sys
import pandas as pd

print("Running save_emails.py")

sys.path.append("mail-client/mail_gmail_impl/src")
sys.path.append("mail-client/mail_api/src")

try:
    from mail_gmail_impl.gmail_client import GmailClient
    print("GmailClient imported successfully")
except Exception as e:
    print(f"Import failed: {e}")

def save_emails_to_csv():
    client = GmailClient()
    print("Created GmailClient")

    emails = []
    for message in client.get_messages():
        print(f"Message ID: {message.id}")
        emails.append({
            "mail_id": message.id,
            "email_body": message.body
        })

    print(f"Total emails: {len(emails)}")

    df = pd.DataFrame(emails)
    df.to_csv("emails.csv", index=False)
    print("Saved emails to emails.csv")

if __name__ == "__main__":
    try:
        save_emails_to_csv()
    except Exception as e:
        print(f"Error during execution: {e}")
