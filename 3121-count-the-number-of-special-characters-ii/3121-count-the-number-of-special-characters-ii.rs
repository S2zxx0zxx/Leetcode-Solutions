use std::collections::HashMap;

impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut last_lower: HashMap<char, usize> = HashMap::new();
        let mut first_upper: HashMap<char, usize> = HashMap::new();

        for (i, c) in word.chars().enumerate() {
            if c.is_lowercase() {
                last_lower.insert(c, i);
            } else if c.is_uppercase() {
                let lc = c.to_lowercase().next().unwrap();
                first_upper.entry(lc).or_insert(i);
            }
        }

        last_lower.iter().filter(|(c, li)| {
            first_upper.get(c).map_or(false, |ui| *li < ui)
        }).count() as i32
    }
}