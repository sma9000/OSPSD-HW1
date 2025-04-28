#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <cstdlib>   
#include <cstdio>    
#include <filesystem>

void removeFile(const std::string& filename) {
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error removing file: " << filename << std::endl;
    } else {
        std::cout << "Removed file: " << filename << std::endl;
    }
}

// End-to-end Integration Test for integrate.cpp
TEST(IntegrateEndToEnd, ProcessEmails) {
    const std::string emailsFile = "sample_emails.csv"; // Use existing sample file
    const std::string resultsFile = "results.csv";

    // Verify that sample_emails.csv exists before running
    ASSERT_TRUE(std::filesystem::exists(emailsFile)) 
        << "sample_emails.csv does not exist in " 
        << std::filesystem::current_path();

    // Set environment variables for the test
    setenv("MOCK_MODE", "true", 1);
    setenv("OPENAI_API_KEY", "dummy_key", 1);
    setenv("OPENAI_API_ENDPOINT", "http://localhost:5000/fake_endpoint", 1);
    setenv("EMAILS_FILE", emailsFile.c_str(), 1); 
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
    infile.close();

    // Verify that the header is present
    EXPECT_NE(resultsContent.find("mail_id,Pct_spam"), std::string::npos)
            << "results.csv header missing";

    
    EXPECT_NE(resultsContent.find(","), std::string::npos)
            << "No mail records found in results.csv";

    // Cleanup: delete only the results file, leave sample_emails.csv intact
    removeFile(resultsFile);
}
