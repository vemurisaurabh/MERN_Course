module.exports = {
  //param A : array of integers
  //param B : array of array of integers
  //return a array of integers
  solve: function (arr, queries) {
    arr = arr.map(Number);
    let n = arr.length;
    let prefixSum = new Array(n).fill(0);
    if (arr[0] % 2 == 0) {
      prefixSum[0] = 1;
    }
    for (let i = 1; i < n; i++) {
      if (arr[i] % 2 == 0) {
        prefixSum[i] = prefixSum[i - 1] + 1;
      } else {
        prefixSum[i] = prefixSum[i - 1];
      }
    }
    let result = new Array(queries.length).fill(0);
    queries.forEach(([left, right], index) => {
      if (left != 0) {
        result[index] = prefixSum[right] - prefixSum[left - 1];
      } else {
        result[index] = prefixSum[right];
      }
    });
    return result;
  },
};
