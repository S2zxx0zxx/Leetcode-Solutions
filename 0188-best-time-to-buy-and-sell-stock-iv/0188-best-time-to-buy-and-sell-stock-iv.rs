impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let n = prices.len();
        let k = k as usize;
        if n == 0 || k == 0 {
            return 0;
        }

        let mut buy = vec![i32::MIN; k + 1];
        let mut sell = vec![0; k + 1];

        for &price in prices.iter() {
            for j in 1..=k {
                buy[j] = buy[j].max(sell[j - 1] - price);
                sell[j] = sell[j].max(buy[j] + price);
            }
        }

        sell[k]
    }
}