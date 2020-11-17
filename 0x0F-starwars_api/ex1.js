"use strict";
 
function asyncSqrt(value, callback) {
    console.log('START execution with value =', value); // 3 se ejecuta esta primera linea
	/*callback(value, value*value); */ /* si fuera syncrono*/
	
    setTimeout(function() {  
        callback(value, value * value);  // 6 este callback se ejecuta despues del tiempo
    }, 0 | Math.random() * 100); // 4 se ejecuta esta pero solo hasta que el tiempo pase pero el prog sigue
} 
/* observar que con el for no se ejecutan 0,1,2,3...si no en desorden*/
/* esto se debe a que se esta ejecutando de forma asyncrona, esto es q tanto como se va
 * ejecutando se va retornando el control */
for (var n = 0; n < 10; n++) { 
	asyncSqrt(n, function(value, result) { // 7 una vez se ejecuta el callback se ejecuta esta correspondinete
	    console.log('END execution with value =', value, 'and result =', result);
	}); // 2 se ordena la ejecucion de la funcion desde su primera linea START...
}/*for*/
console.log('COMPLETED ?'); // 5 como se ejecutó todo lo de asyncSqrt sigue y ejecuta esto

/* primero imprime START....
 * mete a la cola de ejecucion el settiem out, una vez termine ejecuta el calculo value*value y pasa el control
 * ejecuta el call back de asycSqrt para que se imprima en END...esto solo si ha terminado el calculo ya q 
 * esta en un timeout, si ha terminado entonces imprime END...
 * imprime COMPLETED
 * asi las cosas el STAR siempre se imprime de primero, pero es posible q el COMPLETED  se imprima antes del END
 */
