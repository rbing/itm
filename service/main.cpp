#include <sstream>
#include "httplib.h"
#include "itm.h"

int main(int argc, char** argv)
{
  // HTTP
  httplib::Server svr;

  // HTTPS
  // httplib::SSLServer svr;

  double h_tx__meter = 15.;
  double h_rx__meter = 3.;
  int climate = 5;
  double N_0 = 301.;
  double f__mhz = 3500.;
  int pol = 1;
  double epsilon = 15.;
  double sigma = 0.005;
  int mdvar = 1;
  double time = 50;
  double location = 50;
  double situation = 50;

  double A__db = 0.;
  long warnings = 0;
  std::string pfl_str = "142,25.6,1692,1692,1693,1693,1693,1693,1693,1693,1694,1694,1694,1694,1694,1694,1694,1694,1694,1695,1695,1695,1695,1695,1695,1695,1695,1696,1696,1696,1696,1696,1696,1697,1697,1697,1697,1697,1697,1697,1697,1697,1697,1698,1698,1698,1698,1698,1698,1698,1698,1698,1698,1699,1699,1699,1699,1699,1699,1700,1700,1700,1700,1700,1700,1700,1701,1701,1701,1701,1701,1701,1702,1702,1702,1702,1702,1702,1702,1702,1703,1703,1703,1703,1703,1703,1703,1703,1703,1704,1704,1704,1704,1704,1704,1704,1704,1705,1705,1705,1705,1705,1705,1705,1705,1705,1705,1706,1706,1706,1706,1706,1706,1706,1706,1706,1707,1707,1707,1707,1707,1707,1707,1708,1708,1708,1708,1708,1708,1708,1708,1709,1709,1709,1709,1709,1710,1710,1710,1710,1710,1710,1710,1710,1709";
  stringstream ss(pfl_str);
  std::vector<double> pfl_vec;
  std::string val;
  while (getline(ss, val, ','))
  {
    pfl_vec.push_back(std::stod(val));
  }

  int result = ITM_P2P_TLS(h_tx__meter, h_rx__meter, pfl_vec.data(), climate, N_0, f__mhz, pol, epsilon, sigma, mdvar, time, location, situation, &A__db, &warnings);

  svr.Get("/hi",
    [](const httplib::Request&, httplib::Response& res)
    {
      res.set_content("Hello World!", "text/plain");
    });

  svr.Get("/stop",
    [&](const httplib::Request& req, httplib::Response& res)
    {
      svr.stop();
    });

  svr.listen("localhost", 8081);
}
