const heading = document.querySelector("h1");
const para = document.querySelector("p");
const div = document.querySelector(".box");

heading.innerHTML = "helowwwwwwwwwwwwwdas";

const arr = [1, 2, 3];
let n = arr.length;
let ans = [];
for (let i = 0; i < n; i++) {
  let subArray = [];
  for (let j = i; j < n; j++) {
    subArray.push(arr[j]);
    ans.push(subArray);
  }
}
console.log(ans);
