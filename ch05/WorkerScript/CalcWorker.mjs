WorkerScript.onMessage = (msg) => {
    if (msg === "doCalc1") {
        WorkerScript.sendMessage( {newState : "running"})
        var i;
        var sum = 0;
        for (i = 0; i < 10000; ++i) {
            var j;
            for (j = 0; j < 20000; ++j) {
                sum += j * i;
            }
            if (i % 1000) {
                WorkerScript.sendMessage( { newText : "working... " + (i / 1000) } )
            }
        }
        WorkerScript.sendMessage( { result : sum,
                                    newState : "done"})
    }
}
