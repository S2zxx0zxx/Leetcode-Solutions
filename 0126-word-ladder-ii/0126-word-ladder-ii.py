class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return []
        
        # BFS to build parent map
        layer = {beginWord}
        parents = defaultdict(set)
        found = False
        
        while layer and not found:
            wordSet -= layer
            next_layer = set()
            for word in layer:
                for i in range(len(word)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        newWord = word[:i] + c + word[i+1:]
                        if newWord in wordSet:
                            next_layer.add(newWord)
                            parents[newWord].add(word)
                            if newWord == endWord:
                                found = True
            layer = next_layer
        
        if not found:
            return []
        
        # DFS to build paths
        res = []
        def dfs(word, path):
            if word == beginWord:
                res.append(path[::-1])
                return
            for parent in parents[word]:
                dfs(parent, path + [parent])
        
        dfs(endWord, [endWord])
        return res 