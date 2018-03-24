#include <websocketpp/config/asio_no_tls.hpp>

#include <websocketpp/server.hpp>

#include <fstream>
#include <iostream>
#include <set>
#include <streambuf>
#include <string>

#include "CServer/CServer.h"
#include "proxy/proxy.h"

#include <unistd.h>

#include "config.h"

using std::cout;
using std::endl;

/**
 * The telemetry server accepts connections and sends a message every second to
 * each client containing an integer count. This example can be used as the
 * basis for programs that expose a stream of telemetry data for logging,
 * dashboards, etc.
 *
 * This example uses the timer based concurrency method and is self contained
 * and singled threaded. Refer to telemetry client for an example of a similar
 * telemetry setup using threads rather than timers.
 *
 * This example also includes an example simple HTTP server that serves a web
 * dashboard displaying the count. This simple design is suitable for use
 * delivering a small number of files to a small number of clients. It is ideal
 * for cases like embedded dashboards that don't want the complexity of an extra
 * HTTP server to serve static files.
 *
 * This design *will* fall over under high traffic or DoS conditions. In such
 * cases you are much better off proxying to a real HTTP server for the http
 * requests.
 */

// void setCallback(std::function<std::string(std::string)> callback){
//   callback("TeSt!");
// }
//
// std::string fncallback(std::string a) {
//   std::cout << "callback: " << a << std::endl;
//   return "Final test";
// }

int main(int argc, char* argv[]) {
    CServer s;

    std::string docroot;
    uint16_t port = 9000;

    if (argc == 1) {
        docroot = "/var/www/html";
    }

    if (argc >= 2) {
        docroot = std::string(argv[1]);
    }

    if (argc >= 3) {
        int i = atoi(argv[2]);
        if (i <= 0 || i > 65535) {
            std::cout << "invalid port" << std::endl;
            return 1;
        }

        port = uint16_t(i);
    }

    chdir(docroot.c_str());
    proxy *p = new proxy();
    s.setCallback(p);

    s.run(docroot, port);
    return 0;
}
