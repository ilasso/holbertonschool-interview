"use strict";

/* una de las soluciones es esperar el fin de la ejecución*/
 
function asyncSqrt(value, callback) {
    console.log('START execution with value =', value); 
	
    setTimeout(function() {  
        callback(value, value * value);  
    }, 0 | Math.random() * 100); 
} 

var max = 10
var cnt = 0
for (var n = 0; n < max; n++) { 
	asyncSqrt(n, function(value, result) { 
	    console.log('END execution with value =', value, 'and result =', result);
		if(++cnt === max) {
			console.log('COMPLETED ?'); 
		}
	}); 
}
//console.log('COMPLETED old?'); 
