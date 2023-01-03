class NetCanvas {
    constructor() {
        this.ws = null;
        this.connected = false;
    }

    connect(addr) {
        this.ws = new WebSocket(addr);
        this.ws.onopen = this.onopen.bind(this);
        this.ws.onmessage = this.onmessage.bind(this);
        this.ws.onclose = this.onmessage.bind(this);
    }

    onopen(evt) {
        this.ws.send("test");
    }

    onmessage(evt) {
        console.log(evt.data);
    }

    onclose(evt) {

    }
}