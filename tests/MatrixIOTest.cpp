#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "MatrixIO.hpp"

using namespace Eigen;

struct MatrixSolverFixture {
  MatrixSolverFixture()
  {
    expected = MatrixXd(3, 3);
    expected << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }

  MatrixXd expected;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixSolverFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openM3)
{
  // A is read from file, b is set randomly, x is the solution
  const MatrixXd      A = matrixIO::openData("data/m3.csv", 3);
  std::vector<double> vecA(A.data(), A.data() + A.size());
  std::vector<double> vecB(expected.data(), expected.data() + expected.size());

  BOOST_CHECK_EQUAL_COLLECTIONS(vecA.begin(), vecA.end(), vecB.begin(), vecB.end());
}


BOOST_AUTO_TEST_SUITE_END()
