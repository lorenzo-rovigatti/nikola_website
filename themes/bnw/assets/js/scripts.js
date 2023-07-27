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

/* used in the page displaying the list of publications */
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

/* load configurations into oxview */
function load_oxview_conf(configuration, topology, frame_id) {
  inbox_settings = ["Monomer", "Origin"]
  let t_files = [configuration, topology];
  let t_blobs = []
  for(let i = 0; i < t_files.length; i++){
    let f = new XMLHttpRequest();
    f.open("GET", t_files[i], false);
    f.onreadystatechange = function () {
        t_blobs.push(new Blob([f.responseText], {type : 'text/plain'}));
    }
    f.send(null)
  }
  let t_ext = ["top", "dat"];
  const frame = document.getElementById(frame_id);
  frame.contentWindow.postMessage({message : 'iframe_drop', files: t_blobs, ext: t_ext, inbox_settings: inbox_settings}, "https://sulcgroup.github.io/oxdna-viewer/");
}

function enable_fieldset(fieldset_id) {
  document.getElementById(fieldset_id).disabled = false;
}
