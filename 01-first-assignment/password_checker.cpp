/*
错误说明：

1. 数字判断：
   原代码使用数值 0、9 作为字符范围，
   应改为字符 '0'、'9'。

2. 长度判断：
   原代码使用 <= 10，与“长度至少 10”相反，
   应改为 >= 10。

3. 范围边界：
   原代码使用严格小于，漏掉范围端点，
   应改为包含端点的 <=，让 A、Z、a、z、0、9 能通过。

4. 编译警告：
   删除没有使用的 checked 变量。

补充测试：
输入：Chen Liu Cc12345678
预期输出：VALID
原因：长度为 10，包含大写、小写和数字，
      并且不包含名 Chen 或姓 Liu。
*/
#include <iostream>
#include <string>

bool contains_between(const std::string& text,
                      char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    bool name_ok =
        password.find(first_name) == std::string::npos &&
        password.find(last_name) == std::string::npos;

    return length_ok && upper_ok && lower_ok &&
           digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;

    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }

    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID")
              << '\n';
    return 0;
}
