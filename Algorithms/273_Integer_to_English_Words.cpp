#include <string>
using std::string;

const int cap[] = {1000000, 1000, 1};
const char *thousand_str = "Thousand";
const char *million_str = "Million";
const char *billion_str = "Billion";
const char *hundred_str = "Hundred";
const char *cap_str[] = {million_str, thousand_str, ""};

const char *unit_str[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const char *tens_str[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                          "Seventeen", "Eighteen", "Nineteen"
                         };
const char *d_str[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                       "Eighty", "Ninety"
                      };


class Buffer {
public:
    Buffer() {}
    Buffer(const Buffer& other): inner(other.inner) {}

    Buffer& operator=(const Buffer& other) {
        this->inner = other.inner;
        return *this;
    }

    Buffer& operator=(Buffer&& other) {
        this->inner = other.inner;
        return *this;
    }

    string take() {
        string str;
        std::swap(str, this->inner);
        return std::move(str);
    }

    template <typename T>
    friend Buffer& operator<<(Buffer& os, T t) {
        os.inner.append(t);
        return os;
    }
private:
    string inner;
};

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return unit_str[0];
        }

        Buffer buf;
        this->solve(buf, num);
        return std::move(buf.take());
    }

private:
    void dealWithHundred(Buffer& buf, int n) {
        if (n == 0) return;

        int unit = n % 10;
        n /= 10;
        int tens = n % 10;
        n /= 10;
        int hund = n % 10;

        if (hund != 0) {
            buf << unit_str[hund] << " " << hundred_str;
            if (tens != 0 || unit != 0)
                buf << " ";
        }

        if (tens != 0) {
            if (tens != 1) {
                buf << d_str[tens];

                if (unit != 0) {
                    buf << " " << unit_str[unit];
                }
            } else {
                buf << tens_str[unit];
            }
        } else if (unit != 0) {
            buf << unit_str[unit];
        }
    }

    void solve(Buffer& buf, int n) {
        // Billion
        int bil = n / 1000000000;
        n %= 1000000000;

        if (bil != 0) {
            this->solve(buf, bil);
            buf << " " << billion_str;
            if (n != 0) {
                buf << " ";
            }
        }

        for (size_t i = 0; i < 3; ++i) {
            int caps = n / cap[i];
            n %= cap[i];

            if (caps != 0) {
                this->dealWithHundred(buf, caps);

                if (i != 2) {
                    buf << " " << cap_str[i];

                    if (n != 0) {
                        buf << " ";
                    }
                }
            }
        }
    }
};
