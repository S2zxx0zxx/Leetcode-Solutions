class EventEmitter {
    constructor() {
        this.events = {};
    }
    
    subscribe(eventName, callback) {
        if (!this.events[eventName]) {
            this.events[eventName] = [];
        }
        this.events[eventName].push(callback);
        
        return {
            unsubscribe: () => {
                const idx = this.events[eventName].indexOf(callback);
                this.events[eventName].splice(idx, 1);
                return undefined;
            }
        };
    }
    
    emit(eventName, args = []) {
        if (!this.events[eventName]) return [];
        return this.events[eventName].map(cb => cb(...args));
    }
}