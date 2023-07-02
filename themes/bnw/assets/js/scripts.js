/* add click event for navbar-toggle item */
$(function() {
  $('#btn-toggle-nav').click(function() {
    var item = $('nav.navbar-collapse');
    item.slideToggle(500, function() {
      item[0].style.removeProperty('display');
      item.toggleClass('in');
    });
  })
});

// headroom
var header = document.querySelector("header");
var headroom  = new Headroom(header);
headroom.init(); 

function scroll_to_year_list() {
  headroom.freeze()
  const element = document.getElementById("publication-year-list");
  element.scrollIntoView();
  
  // taken from https://stackoverflow.com/a/73384237/5140209
  currPageXOffset = window.pageXOffset;
  currPageYOffset = window.pageYOffset;
  var scrollDone = setInterval(function () {
      if(currPageXOffset == window.pageXOffset && currPageYOffset == window.pageYOffset) {
          clearInterval(scrollDone);
          headroom.unfreeze();
      }
      currPageXOffset = window.pageXOffset;
      currPageYOffset = window.pageYOffset;
  }, 50);
}
