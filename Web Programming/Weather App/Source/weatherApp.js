/**
 * Created by kevin on 4/24/2017.
 */

/* code that runs when Web page is first loaded and rendered by the browser */
left = 0;

// var init={
//     init: function(){
//         var range = document.getElementById("range");
//         var rangeWidth = range.clientWidth;
//         var steppers = document.getElementsByClassName("stepper");
//         var n = steppers.length;
//
//         var totalspace = rangeWidth - (5*steppers[0].clientWidth); // total space after stepper size is taken out
//         var unitspace = totalspace / n-1; // spaces to be given to each stepper
//
//         if (unitspace > 0){
//             for (i = 1; i < n; i++) {
//                 left = left + unitspace;
//                 steppers[i].style.left = left + "px";
//             }
//         }
//     }
// };

/* view{} handles most mechanics related to data visualization */
var view={
    buttonActionL: function(){ // Pulled from lecture example
        var steppers = document.getElementsByClassName("stepper");
        var range = document.getElementById("range");
        var rangeWidth = range.clientWidth;
        var stepWidth = steppers[0].clientWidth;
        var n = steppers.length;
        for (i = 0; i < n; i++) {
            //if (left > -5*stepWidth) {
                left = left - 30;
                steppers[i].style.left = left + "px";
        }
    },

    buttonActionR: function(){ // Pulled from lecture example
        // for (i = 0; i < 10; i++){
        //     var steppy = document.getElementById("day"+i);
        //
        //     // left = left+10;
        //     // steppy.style.left = left+"px";
        //
        //     // var container = steppy.parentElement; // "range"
        //     // var width = container.clientWidth; // width of weather box
        //     // var positionInfo = steppy.getBoundingClientRect();
        //
        //     // if (left < width-225) {
        //     //     left = left+positionInfo.width;
        //     left = left + 30;
        //     steppy.style.left = left+"px";
        //     // }
        // }
        var steppers = document.getElementsByClassName("stepper");
        var range = document.getElementById("range");
        var rangeWidth = range.clientWidth;
        var stepWidth = steppers[0].clientWidth;
        var n = steppers.length;
        for (i = 0; i < n; i++) {
            //if (left < 5*stepWidth){
                left = left + 30;
                steppers[i].style.left = left + "px";

        }
    }
};

var ctrl={
    pullWeather: function(){
        var zip = document.getElementById("search").value;
        var script = document.createElement('script');
        script.src = "https://query.yahooapis.com/v1/public/yql?q=select woeid,name,admin1,country  from   geo.places where text='"+zip+"' & format=json & callback=control.placeCallback";
        document.body.appendChild(script);    }
};