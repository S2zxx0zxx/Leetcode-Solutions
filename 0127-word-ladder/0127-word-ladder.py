class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0
        
        queue = deque([(beginWord, 1)])
        
        while queue:
            word, steps = queue.popleft()
            
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    newWord = word[:i] + c + word[i+1:]
                    if newWord == endWord:
                        return steps + 1
                    if newWord in wordSet:
                        wordSet.remove(newWord)
                        queue.append((newWord, steps + 1))
        
        return 0