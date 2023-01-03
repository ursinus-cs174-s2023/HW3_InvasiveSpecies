const CIRCLE = 0;
const SQUARE = 1;

class NetCanvas {
    constructor() {
        this.ws = null;
        this.connected = false;
        // Figure out a good resolution
        let res = 0.8*Math.min(window.innerWidth, window.innerHeight);
        this.res = res;
        // Add an svg element with this resolution
        this.svg = d3.select("#canvas")
                    .append("svg")
                    .attr("width", res)
                    .attr("height", res);
    }

    connect(addr) {
        this.ws = new WebSocket(addr);
        this.ws.binaryType = 'arraybuffer';
        this.ws.onopen = this.onopen.bind(this);
        this.ws.onmessage = this.onmessage.bind(this);
        this.ws.onclose = this.onmessage.bind(this);
    }

    onopen(evt) {
        this.ws.send("draw");
    }

    onmessage(evt) {
        let fbuf = new Float32Array(evt.data);
        let bbuf = new Uint8Array(evt.data);
        let i = 0;
        let circles = [];
        while (i < bbuf.length) {
            let r = bbuf[i+1];
            let g = bbuf[i+2];
            let b = bbuf[i+3];
            if (bbuf[i] == CIRCLE) {
                i += 4;
                let circle = {"fill":"rgb("+r+","+g+","+b+")"};
                circle.cx = fbuf[i/4]*this.res;
                i += 4;
                circle.cy = fbuf[i/4]*this.res;
                i += 4;
                circle.r = fbuf[i/4]*this.res;
                i += 4;
                circles.push(circle);
            }
        }
        this.repaint({"circles":circles});
    }

    onclose(evt) {

    }

    repaint(shapes) {
        const svg = this.svg;
        svg.selectAll('*').remove();
        let circles = svg.selectAll(null)
            .data(shapes.circles)
            .enter()
            .append("circle");

        circles.attr("cx", d=>d.cx);
        circles.attr("cy", d=>d.cy);
        circles.attr("r", d=>d.r);
        circles.attr("fill", d=>d.fill);

        this.ws.send("draw");
    }
}