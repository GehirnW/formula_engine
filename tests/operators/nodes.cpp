#include <fel/operators/nodes.hpp>
#include <fel/settings.hpp>
#include <gtest/gtest.h>

using namespace FEngine;

TEST(TestNodes, TestLast) {
    DataPack data;
    data["aapl"] = Map_<String_, Map_<DateTime, double>>();
    data["ibm"] = Map_<String_, Map_<DateTime, double>>();
    data["aapl"]["close"] = Map_<DateTime, double>();
    data["ibm"]["close"] = Map_<DateTime, double>();
    data["aapl"]["close"][Date("2018-01-05")] = 2.;
    data["ibm"]["close"][Date("2018-01-05")] = 3.;

    GlobalSymbols symbols({"aapl", "ibm"});
    Last close("close");
    Series res = close.calculate(data, Date("2018-01-05"));

    ASSERT_EQ(res["aapl"], 2.);
    ASSERT_EQ(res["ibm"], 3.);
}

TEST(TestNodes, TestPlusOperator) {
    DataPack data;
    data["aapl"] = Map_<String_, Map_<DateTime, double>>();
    data["ibm"] = Map_<String_, Map_<DateTime, double>>();
    data["aapl"]["close"] = Map_<DateTime, double>();
    data["ibm"]["close"] = Map_<DateTime, double>();
    data["aapl"]["close"][Date("2018-01-05")] = 2.;
    data["ibm"]["close"][Date("2018-01-05")] = 3.;

    GlobalSymbols symbols({"aapl", "ibm"});
    Last close1("close");
    Last close2("close");

    PlusOperator combined = close1 + close2;
    Series res = combined.calculate(data, Date("2018-01-05"));

    ASSERT_EQ(res["aapl"], 4.);
    ASSERT_EQ(res["ibm"], 6.);
}

TEST(TestNodes, TestMinusOperator) {
    DataPack data;
    data["aapl"] = Map_<String_, Map_<DateTime, double>>();
    data["ibm"] = Map_<String_, Map_<DateTime, double>>();
    data["aapl"]["close"] = Map_<DateTime, double>();
    data["ibm"]["close"] = Map_<DateTime, double>();
    data["aapl"]["close"][Date("2018-01-05")] = 2.;
    data["ibm"]["close"][Date("2018-01-05")] = 3.;

    GlobalSymbols symbols({"aapl", "ibm"});
    Last close1("close");
    Last close2("close");

    MinusOperator combined = close1 - close2;
    Series res = combined.calculate(data, Date("2018-01-05"));

    ASSERT_EQ(res["aapl"], 0.);
    ASSERT_EQ(res["ibm"], 0.);
}

TEST(TestNodes, TestMultiplyOperator) {
    DataPack data;
    data["aapl"] = Map_<String_, Map_<DateTime, double>>();
    data["ibm"] = Map_<String_, Map_<DateTime, double>>();
    data["aapl"]["close"] = Map_<DateTime, double>();
    data["ibm"]["close"] = Map_<DateTime, double>();
    data["aapl"]["close"][Date("2018-01-05")] = 2.;
    data["ibm"]["close"][Date("2018-01-05")] = 3.;

    GlobalSymbols symbols({"aapl", "ibm"});
    Last close1("close");
    Last close2("close");

    MultiplyOperator combined = close1 * close2;
    Series res = combined.calculate(data, Date("2018-01-05"));

    ASSERT_EQ(res["aapl"], 4.);
    ASSERT_EQ(res["ibm"], 9.);
}

TEST(TestNodes, TestDivideOperator) {
    DataPack data;
    data["aapl"] = Map_<String_, Map_<DateTime, double>>();
    data["ibm"] = Map_<String_, Map_<DateTime, double>>();
    data["aapl"]["close"] = Map_<DateTime, double>();
    data["ibm"]["close"] = Map_<DateTime, double>();
    data["aapl"]["close"][Date("2018-01-05")] = 2.;
    data["ibm"]["close"][Date("2018-01-05")] = 3.;

    GlobalSymbols symbols({"aapl", "ibm"});
    Last close1("close");
    Last close2("close");

    DivideOperator combined = close1 / close2;
    Series res = combined.calculate(data, Date("2018-01-05"));

    ASSERT_EQ(res["aapl"], 1.);
    ASSERT_EQ(res["ibm"], 1.);
}
