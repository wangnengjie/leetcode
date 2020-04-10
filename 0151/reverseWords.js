const reverseWords = function (s) {
  let v = s.split(" ");
  s = v.filter((e) => e.length !== 0);
  s.reverse();
  return s.join(" ");
};
