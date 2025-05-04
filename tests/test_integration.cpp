#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <string>

TEST(IntegrationTest, PipelineProducesResultsFile) {
    // Clean any old file
    std::remove("results.csv");

    // Call the binary (assumes sample_emails.csv exists from configure_file)
    int ret = std::system("Release\\run_pipeline.exe >nul");
    ASSERT_EQ(ret, 0) << "Pipeline execution failed.";

    // Validate the output file
    std::ifstream result("results.csv");
    ASSERT_TRUE(result.is_open()) << "results.csv not created.";

    std::string header;
    std::getline(result, header);
    EXPECT_EQ(header, "mail_id,Pct_spam");

    int line_count = 0;
    std::string line;
    while (std::getline(result, line)) {
        line_count++;
        EXPECT_NE(line.find(','), std::string::npos);  // Contains comma
    }

    EXPECT_GT(line_count, 0) << "No spam scores written.";
}
