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

/*
 WorkerScript.onMessage = function(message) {
     //Calculate result (may take a while, using a naive algorithm)
     var calculatedResult = triangle(message.row, message.column);
     //Send result back to main thread
     WorkerScript.sendMessage( { row: message.row,
                                 column: message.column,
                                 result: calculatedResult} );
 }
*/
