#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <string>

TEST(IntegrationTest, PipelineProducesResultsFile) {
    std::remove("results.csv");

    // Verify that pandas is available
    int ret = std::system("python3 /root/project/scripts/run_pipeline.py > pipeline.log 2>&1");
    ASSERT_EQ(ret, 0) << "Pipeline execution failed. Check pipeline.log for details.";


    // Run pipeline script
    ret = std::system("python3 ../scripts/run_pipeline.py > /dev/null");
    ASSERT_EQ(ret, 0) << "Pipeline execution failed.";

    // Validate output
    std::ifstream result("results.csv");
    ASSERT_TRUE(result.is_open()) << "results.csv not created.";

    std::string header;
    std::getline(result, header);
    EXPECT_EQ(header, "mail_id,Pct_spam");

    int line_count = 0;
    std::string line;
    while (std::getline(result, line)) {
        EXPECT_NE(line.find(','), std::string::npos);
        line_count++;
    }

    EXPECT_GT(line_count, 0) << "No spam scores written.";
}

