#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <cstdlib>   // setenv and system()
#include <cstdio>    // remove()
#include <filesystem> // file path debugging and verification

// Create a temporary CSV file in the working directory
void createTemporaryEmailsCSV(const std::string& filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create " << filename << " in " 
                  << std::filesystem::current_path() << std::endl;
        throw std::runtime_error("Could not create " + filename);
    }
    std::cout << "Created file: " << filename << std::endl;

    // Write header and one email record
    outfile << "mail_id,email_body\n";
    outfile << "This is a test email that should be analyzed.\n";
    outfile.close();
}

void removeFile(const std::string& filename) {
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error removing file: " << filename << std::endl;
    } else {
        std::cout << "Removed file: " << filename << std::endl;
    }
}

// End-to-end Integration Test for integrate.cpp
TEST(IntegrateEndToEnd, ProcessEmails) {
    const std::string emailsFile = "sample_emails.csv"; // Updated file name
    const std::string resultsFile = "results.csv";

    createTemporaryEmailsCSV(emailsFile);

    // Set environment variables for the test
    setenv("MOCK_MODE", "true", 1);
    setenv("OPENAI_API_KEY", "dummy_key", 1);
    setenv("OPENAI_API_ENDPOINT", "http://localhost:5000/fake_endpoint", 1);
    setenv("EMAILS_FILE", emailsFile.c_str(), 1); // Pass file paths explicitly
    setenv("RESULTS_FILE", resultsFile.c_str(), 1);

    // Run the integrate executable
    int ret = system("./integrate");
    EXPECT_EQ(ret, 0) << "Integrate executable did not exit with 0";

    // Check that the results file exists
    std::ifstream infile(resultsFile);
    EXPECT_TRUE(infile.good()) << "results.csv was not created";

    // Read the entire contents of results.csv
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string resultsContent = buffer.str();

    // Verify that the header is present
    EXPECT_NE(resultsContent.find("mail_id,Pct_spam"), std::string::npos)
            << "results.csv header missing";
  
    // Verify that our test mail record (mail_id "1") is included
    EXPECT_NE(resultsContent.find("1,"), std::string::npos)
            << "Processed email record for mail_id 1 missing";

    // Cleanup: delete temporary files
    infile.close();
    removeFile(emailsFile);
    removeFile(resultsFile);
}

