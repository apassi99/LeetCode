class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1.size() <= 0 || num2.size() <= 0) {
            return "";
        }

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        if (num1.size() < num2.size()) {
            return multiply(num2, num1);
        }

        vector<vector<char>> results;
        int carry = 0;

        for (int i = num2.size() - 1; i >= 0; i--) {

            int a = num2[i] - '0';
            vector<char> str_result;
            carry = 0;

            for (int k = 0; k < num2.size() - 1 - i; k++) {
                str_result.push_back('0');
            }

            for (int j = num1.size() - 1; j >= 0; j--) {

                int b = num1[j] - '0';
                int r = (a * b) + carry;
                carry = r / 10;
                r = r % 10;

                str_result.push_back(r + '0');
            }

            if (carry > 0) {
                str_result.push_back(carry + '0');
            }

            results.push_back(str_result);
        }

        return add(&results);

    }

private:

    string add(vector<vector<char>> *numbers) {

        vector<char> sum;
        addHelper(numbers, 0, &sum);

        string result;

        for (int i = sum.size() - 1; i >= 0; i--) {
            result.push_back(sum[i]);
        }

        return result;
    }

    void addHelper(vector<vector<char>> * v, int index, vector<char> * currentSum) {
        if (index >= v->size()) {
            return;
        }

        vector<char> num1 = (*v)[index];

        vector<char> currentResult;

        int count = 0;
        int carry = 0;
        int num1size = num1.size();
        int curSumSize = currentSum->size();

        while (count < num1size || count < curSumSize) {
            int n1 = (count < num1size) ? num1[count] - '0' : 0;
            int n2 = (count < curSumSize) ? (*currentSum)[count] - '0' : 0;

            int r = n1 + n2 + carry;
            carry = r / 10;
            r = r % 10;

            if (count >= curSumSize) {
                currentSum->push_back(r + '0');
            } else {
                (*currentSum)[count] = r + '0';
            }
            count++;
        }

        if (carry > 0) {
            currentSum->push_back(carry + '0');
        }

        addHelper(v, index+1, currentSum);

    }
};
