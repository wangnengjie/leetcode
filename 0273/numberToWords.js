/**
 * @param {number} num
 * @return {string}
 */
const numberToWords = num => {
  if (num == 0) {
    return "Zero";
  }
  const a = [
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine"
  ];
  const b = [
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen"
  ];
  const c = [
    "",
    "",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"
  ];
  const format = number => {
    let s = [];
    let i = Math.floor(number / 100);
    i > 0 && s.push(a[i], "Hundred");
    number = number % 100;
    if (number < 20) {
      if (number < 10) {
        number != 0 && s.push(a[number]);
      } else {
        s.push(b[number - 10]);
      }
    } else {
      s.push(c[Math.floor(number / 10)]);
      number = number % 10;
      number != 0 && s.push(a[number]);
    }
    return s;
  };
  re = [];
  for (let i = 0, n; i < 4; i++) {
    switch (i) {
      case 0:
        n = Math.floor(num / 1000000000);
        n != 0 && re.push(...format(n), "Billion");
        break;
      case 1:
        n = Math.floor((num % 1000000000) / 1000000);
        n != 0 && re.push(...format(n), "Million");
        break;
      case 2:
        n = Math.floor((num % 1000000) / 1000);
        n != 0 && re.push(...format(n), "Thousand");
        break;
      case 3:
        n = num % 1000;
        n != 0 && re.push(...format(n));
    }
  }
  return re.join(" ");
};
