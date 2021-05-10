const map: Record<number | string, number> = {
  1: 1,
  2: 2,
  3: 3,
  4: 4,
  5: 5,
  6: 6,
  7: 7,
  8: 8,
  9: 9,
  a: 10,
  b: 11,
  c: 12,
  d: 13,
  e: 14,
  f: 15,
};

function hex2binary(hex: string) {
  hex = hex.slice(2);

  let rs = "";

  for (let i = 0; i < hex.length; i++) {
    const n = hex[i].toLocaleLowerCase();

    rs += map[n].toString(2);
  }

  return rs;
}

console.log("16 to 2", hex2binary("ox8f7a93"));

function binary2hex(binary: string) {
  let len = binary.length;

  while (len % 4 !== 0) {
    binary = "0" + binary;
    len = binary.length;
  }

  let rs = "0x";

  for (let i = 0; i < binary.length; i += 4) {
    const h = binary.slice(i, i + 4);

    rs += parseInt(h, 2).toString(16);
  }

  return rs;
}

console.log("2 to 16", binary2hex("1011011110011100"));
