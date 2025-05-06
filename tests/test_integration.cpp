#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <string>

TEST(IntegrationTest, PipelineProducesResultsFile) {
    std::remove("results.csv");

    // Use environment-defined Python path or fallback to python3
    const char* python_path = std::getenv("PYTHON_BIN");
    std::string python = python_path ? python_path : "python3";

    // First check that pandas is importable
    std::string ret1_cmd = python + " /root/project/scripts/run_pipeline.py > pipeline.log 2>&1";
    int ret = std::system(ret1_cmd.c_str());
    ASSERT_EQ(ret, 0) << "Pipeline execution failed. Check pipeline.log for details.";

    // Run pipeline again to generate output
    std::string ret2_cmd = python + " ../scripts/run_pipeline.py > /dev/null";
    ret = std::system(ret2_cmd.c_str());
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
