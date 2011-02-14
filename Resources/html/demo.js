/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */


/**
 * Set the ID of the body element based on device type
 */
function setBodyDeviceId () {
    if ((navigator.userAgent.match(/iPhone/i)) || (navigator.userAgent.match(/iPod/i))) {
        document.body.id = "iPhone";
    } else {
        document.body.id = "iPad";
    }
}

/**
 * Create the contents of the word cloud on the Introduction page
 */
function createWordCloud() {
    
    /* set content of wordCloud based on device type */
    if ((navigator.userAgent.match(/iPhone/i)) || (navigator.userAgent.match(/iPod/i))) {
        var wordCloud = document.getElementById("introduction_wordCloud_words");
        wordCloud.innerHTML = "Wordnik • is • abaci • cerograph glyphography • the • most • kernel oceanic • comprehensive • dictionary  ignimbrite • in • the • technetronic  known • universe • vengeance • kef ";
    }
}

/**
 * Functions to be executed on first window load
 */
window.onload = function() {
    
    /* set body.id based on device type */
    setBodyDeviceId();
    
    /* display contents of web page after orientation has been determined to prevent CSS hiccups */
    document.body.style.display = "block";
    
    /* change body class when device is rotated; embedded web views do not properly recoginize orientation change events */
    window.onresize = function() { setBodyOrientationClass(); }
}
