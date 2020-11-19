"use strict";

/*
 * @data: es un array con los valores que se van a procesar
 * @each:El segundo parámetro es la función que realiza la 
 *      ejecución para cada llamada. Esta función recibe el 
 *      valor que le corresponde, una matriz para guardar los 
 *      resultados y una función next() para llamar cuando se 
 *      haya completado el paso.
 * @finish:El tercer parámetro es la función que se ejecutará
 *         al finalizar la ejecución completa y recibe en una 
 *         matriz el resultado de todas las llamadas.
 * @sync: Por último, el cuatro parámetro indica si la llamada
 * 	  se hace de forma secuencial (true) o de forma paralela (false). 
 * 	  Prueba a cambiar este último parámetro y vuelve a ejecutar el ejemplo. 
 * 	  Verás que el resultado es completamente diferente.
 */
 
function forEachAll(data, each, finish, sync) {
    var n = -1, result = [];
    var next = sync ?
        function () {
            if (++n < data.length) { each(data[n], result, next); }
            else if (finish)       { finish(result); }
        } :
        (function () {
            function completed() {
                if (++n <= data.length && finish) { finish(result); }
            }
            for (var i = 0; i < data.length; i++) { each(data[i], result, completed); }
            return completed;
        }());
    next();
}
 
function asyncSqrt(value, callback) {
    console.log('START execution with value =', value);
    setTimeout(function() {
        callback(value, value * value);
    }, 0 | Math.random() * 100);
}
 
forEachAll([0,1,2,3,4,5,6,7,8,9],
    function(value, allresult, next) {
        asyncSqrt(value, function(value, result) {
            console.log('END execution with value =', value, 'and result =', result);
            allresult.push({value: value, result: result});
            next();
        });
 
    },
    function(allresult) {
        console.log('COMPLETED');
        console.log(allresult);
    },
  true  
);
