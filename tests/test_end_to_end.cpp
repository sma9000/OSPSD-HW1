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
    const std::string emailsFile = "emails.csv"; // generated or copied file
    const std::string resultsFile = "results.csv";

    // Verify emails.csv exists
    ASSERT_TRUE(std::filesystem::exists(emailsFile)) 
        << "emails.csv does not exist in " 
        << std::filesystem::current_path();

    // Build the command with environment variables
    std::string command =
        "EMAILS_FILE=" + emailsFile +
        " RESULTS_FILE=" + resultsFile +
        " ./integrate";

    // Run the integrate executable
    int ret = system(command.c_str());
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

    // Verify that there is at least one record
    EXPECT_NE(resultsContent.find(","), std::string::npos)
            << "No mail records found in results.csv";

    // Cleanup: delete only the results file, leave emails.csv intact
    removeFile(resultsFile);
}
