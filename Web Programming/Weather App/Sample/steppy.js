/* code that runs when Web page is first loaded and rendered by the browser */
left = 0;


/* functions defined when Web page is loaded, but run when button is pushed. */
function buttonAction() {

	var steppy = document.getElementById("stepper");

	left = left+10;
	steppy.style.left = left+"px";


	var container = steppy.parentElement;
	var width = container.clientWidth;

	if (left < width-225) {
		left = left+10;
	}
	steppy.style.left = left+"px";

}

