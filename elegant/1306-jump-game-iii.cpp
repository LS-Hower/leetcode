bitset<100000> reach{};
class Solution {
public:
    bool canReach(vector<int>& arr, int start)
    {
        reach.reset();
        return [n = arr.size(), &arr](this auto me, int current) {
            if (!(0 <= current && current < n)) {
                return false;
            }
            if (reach.test(current)) {
                return false;
            }
            reach.set(current);
            const int x = arr[current];
            if (x == 0) {
                return true;
            }
            const int l = current - x;
            const int r = current + x;
            return me(l) || me(r);
        }(start);
    }
};
