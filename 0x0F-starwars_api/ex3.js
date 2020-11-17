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
asyncSqrt(cnt, function callback(value, result) { 
    console.log('END execution with value =', value, 'and result =', result);
	if(++cnt === max) {
		console.log('COMPLETED ?'); 
	}
	else {
		asyncSqrt(cnt, callback);
	}
}); 
