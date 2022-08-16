let box = document.getElementById("box");
box.style.position = "relative"

box.style.left = "0px"
let left = 0;
box.style.top = "0px"
let topi = 0;

let dir1 = 1;
let dir2 = 1;

setInterval(()=>{
    if(left < 0 || left > window.innerWidth - box.clientWidth){
        dir1 *= -1
    }
    if(topi < 0 || topi > window.innerHeight - box.clientHeight){
        dir2 *= -1
    }
    left += dir1
    box.style.left = `${left}px`
    topi += dir2
    box.style.top = `${topi}px`
},10)

