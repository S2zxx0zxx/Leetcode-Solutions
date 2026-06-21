var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const existing = this.cache.get(key);
    const exists = existing && existing.expireAt > now;
    
    if (existing && existing.timer) {
        clearTimeout(existing.timer);
    }
    
    const timer = setTimeout(() => {
        this.cache.delete(key);
    }, duration);
    
    this.cache.set(key, { value, expireAt: now + duration, timer });
    
    return !!exists;
};

TimeLimitedCache.prototype.get = function(key) {
    const entry = this.cache.get(key);
    if (!entry || entry.expireAt <= Date.now()) {
        return -1;
    }
    return entry.value;
};

TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let cnt = 0;
    for (const entry of this.cache.values()) {
        if (entry.expireAt > now) cnt++;
    }
    return cnt;
};