# scripts/fetch_emails.py

import sys
sys.path.append("mail-client/mail_gmail_impl/src")
sys.path.append("mail-client/mail_api/src")

print("Running test_mail_client.py")

try:
    from mail_gmail_impl.gmail_client import GmailClient
    print("GmailClient imported successfully")
except Exception as e:
    print(f"Import failed: {e}")
    sys.exit(1)

def main():
    try:
        client = GmailClient()
        print("Created GmailClient")
        messages = list(client.get_messages())
        print(f"Successfully fetched {len(messages)} emails.")

        for msg in messages[:5]:
            print(f"- ID: {msg.id} | Preview: {msg.body[:60]}")
    except Exception as e:
        print(f"Error while fetching emails: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
