use std::collections::HashMap;

impl Solution {
    pub fn max_jumps(arr: Vec<i32>, d: i32) -> i32 {
        let n = arr.len();
        let mut memo = vec![-1i32; n];

        fn dp(i: usize, arr: &Vec<i32>, d: i32, memo: &mut Vec<i32>) -> i32 {
            if memo[i] != -1 {
                return memo[i];
            }
            let n = arr.len();
            let mut best = 1;

            // right
            for x in 1..=d as usize {
                let j = i + x;
                if j >= n || arr[j] >= arr[i] {
                    break;
                }
                best = best.max(1 + dp(j, arr, d, memo));
            }

            // left
            for x in 1..=d as usize {
                if x > i {
                    break;
                }
                let j = i - x;
                if arr[j] >= arr[i] {
                    break;
                }
                best = best.max(1 + dp(j, arr, d, memo));
            }

            memo[i] = best;
            best
        }

        (0..n).map(|i| dp(i, &arr, d, &mut memo)).max().unwrap_or(1)
    }
}