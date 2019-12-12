#include "pch.h"

#include <iostream>
#include "curl\curl.h"
#include "dll4test.h"


void HelloBing() {
  // let's keep it simple
  // https://www.acodersjourney.com/capture-cpp-libcurl-traffic-in-fiddler/
  CURL* curl;
  CURLcode res;
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.bing.com/search?q=hello+world");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    //Point the curl proxy to fiddler
    //res = curl_easy_setopt(curl, CURLOPT_PROXY, "127.0.0.1:8888");
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK) {
      std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res);
    }
    
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
}
