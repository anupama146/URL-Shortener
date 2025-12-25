#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class URLShortener {
private:
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    string baseURL = "http://short.ly/";
    int counter = 1;

    // Generates a unique short key
    string generateKey() {
        return to_string(counter++);
    }

public:
    // Shorten a long URL
    string shortenURL(const string& longURL) {
        // If already shortened, return existing short URL
        if (longToShort.find(longURL) != longToShort.end()) {
            return baseURL + longToShort[longURL];
        }

        string key = generateKey();
        longToShort[longURL] = key;
        shortToLong[key] = longURL;

        return baseURL + key;
    }

    // Retrieve original URL from short URL
    string getOriginalURL(const string& shortURL) {
        string key = shortURL.substr(baseURL.length());

        if (shortToLong.find(key) == shortToLong.end()) {
            return "URL not found";
        }

        return shortToLong[key];
    }
};

// Driver code
int main() {
    URLShortener shortener;

    string longURL1 = "https://www.google.com";
    string longURL2 = "https://www.github.com";

    string short1 = shortener.shortenURL(longURL1);
    string short2 = shortener.shortenURL(longURL2);

    cout << "Short URL: " << short1 << endl;
    cout << "Original URL: " << shortener.getOriginalURL(short1) << endl;

    cout << "Short URL: " << short2 << endl;
    cout << "Original URL: " << shortener.getOriginalURL(short2) << endl;

    return 0;
}
