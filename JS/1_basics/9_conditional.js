/**
 * If ans Switch
 */

let num = 5;

if( num%2 === 0){
    console.log('num is even');
}else{
    console.log('num is odd');
}

if(num%2 === 0){
    console.log('2의 배수');
}else if(num%3 === 0){
    console.log('3의배수');
}else{
    console.log('2,3 배수가 아님') ;
}

const engDay = 'Monday';

let korDay;

switch(engDay){
    case 'Monday':
        korDay = '월요일';
        break;
    case 'tuesday':
        korDay = '화요일';
        break;
    case 'wednesday':
        korDay = '수요일';
        break;
    case 'thursday':
        korDay = '목요일';
        break;
    case 'friday':
        korDay = '금요일';
        break;
    default:
        korDay = '주말';
        break;
}

console.log(korDay);
