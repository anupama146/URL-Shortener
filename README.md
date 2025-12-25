# URL-Shortener
URL Shortener implementation in C++
# URL Shortener (C++)

## Description
This project implements a simple URL Shortener using C++.
It converts long URLs into short, unique URLs and allows retrieval
of the original URL from the shortened version.

## Key Concepts Used
- Hashing (unordered_map)
- String manipulation
- Object-Oriented Programming
- Unique key generation

## Features
- Shortens long URLs into compact links
- Prevents duplicate entries for the same URL
- Retrieves original URLs efficiently
- O(1) average time complexity for operations

## How It Works
- Each long URL is mapped to a unique numeric key
- Two hash maps are used:
  - Long URL → Short key
  - Short key → Long URL

## Time Complexity
- Shorten URL: O(1)
- Retrieve URL: O(1)

## How to Run
```bash
g++ url_shortener.cpp -o url_shortener
./url_shortener

