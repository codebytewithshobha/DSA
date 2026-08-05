class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        vector<int> freq(10, 0);

        for(int d : digits)
            freq[d]++;

        vector<int> ans;


        for(int first = 1; first <= 9; first++) {

            if(freq[first] == 0)
                continue;

            freq[first]--;

            for(int second = 0; second <= 9; second++) {

                if(freq[second] == 0)
                    continue;

                freq[second]--;

                // last digit must be even
                for(int last = 0; last <= 8; last += 2) {

                    if(freq[last] > 0) {
                        ans.push_back(
                            first * 100 + second * 10 + last
                        );
                    }
                }

                freq[second]++;
            }

            freq[first]++;
        }

        return ans;
    }
};