let target = document.querySelector("#dynamic");
let stringArr = ["Learn to HTML","Learn to CSS",
    "Learn to Javascript", "Learn to Python", "Learn to Ruby"];
let selectString = stringArr[Math.random()*stringArr.length];
let selectStringArr = selectString.split("");

function dynamic(randomArr){
    if(randomArr.length>0){
        target.textContent += randomArr.shift();
        setTimeout(function(){
            dynamic(randomArr);
        },80);
    }
}
dynamic(selectStringArr);
/**
 * 커서 깜빡임 효과 함수
 */
function blink(){
    target.classList.toggle("active");
}
setInterval(blink,500);