class NumArray {
public:
    NumArray(vector<int> &nums) : nums_(nums) {
        bit_ = vector<int>(nums_.size() + 1);
        for (int i = 1; i < bit_.size(); ++i) {
            bit_[i] = nums[i - 1] + bit_[i - 1];
        }
        for (int i = bit_.size() - 1; i >= 1; --i) {
            int last_i = i - lower_bit(i);
            bit_[i] -= bit_[last_i];
        }
    }

    void update(int i, int val) {
        if (val - nums_[i]) {
            add(i, val - nums_[i]);
            nums_[i] = val;
        }
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    vector<int> &nums_;
    vector<int> bit_;

    int sum(int i) {
        ++i;
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit_[i];
        }
        return sum;
    }

    void add(int i, int val) {
        ++i;
        for (; i <= nums_.size(); i += lower_bit(i)) {
            bit_[i] += val;
        }
    }

    inline int lower_bit(int i) {
        return i & -i;
    }
};