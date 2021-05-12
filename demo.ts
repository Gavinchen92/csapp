const map: Record<number | string, number> = {
  0: 0,
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

    let temp = map[n].toString(2);

    temp = "0".repeat(4 - temp.length) + temp;

    rs += temp;
  }
  console.log(rs.length);
  return rs;
}

// console.log("16 to 2", hex2binary("0X8f7a93"));

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

// console.log("2 to 16", binary2hex("1011011110011100"));

function decimal2binary(dec: number) {
  let rs = "";

  do {
    let remainder = dec % 2;
    rs = remainder + rs;

    dec = Math.floor(dec / 2);
  } while (dec !== 0);

  return rs;
}

function demical2hex(dec: number) {
  let rs = "";

  do {
    let remainder = dec % 16;
    rs = remainder + rs;

    dec = Math.floor(dec / 16);
  } while (dec !== 0);

  return "0x" + rs;
}

// console.log(demical2hex(188));

// let str = "[[1,2],[3,4]]";

// const reg1 = /\d+/;
// const reg2 = /(?<=,)\d+/;
// const reg3 = /(?<=,\[)\d+/;
// const reg4 = /\d+(?=\]\])/;

// console.log(str.replace(reg3, "0"));

function hex2decimal(hex: number) {
  let rs = 0;
  let hexS = hex.toString(16);

  let i = hexS.length - 1;
  let n = 0;

  while (i >= 0) {
    rs += map[hexS[i].toLocaleLowerCase()] * Math.pow(16, n);
    n++;
    i--;
  }

  return rs;
}

// console.log(hex2decimal(0x12));

function pow2hex(n: number) {
  const map: Record<number, number> = {
    0: 1,
    1: 2,
    2: 4,
    3: 8,
  };

  const remainder = n % 4;

  const time = Math.floor(n / 4);

  return "0x" + map[remainder] + "0".repeat(time);
}

function anwer(n?: number, demical?: number, hex?: string) {
  if (n) {
    return [n, Math.pow(2, n), pow2hex(n)];
  } else if (demical) {
    const binary = decimal2binary(demical);
    n = binary.length - 1;

    return [n, demical, pow2hex(n)];
  } else if (hex) {
    let temp = hex.slice(2);

    n = decimal2binary(Number(temp[0])).length - 1 + (temp.length - 1) * 4;

    return [n, Math.pow(2, n), hex];
  }

  throw new Error("请传递至少一个参数");
}

// console.log(anwer(undefined, undefined, "0x10000"));

console.log(
  hex2binary("0xc3"),
  hex2binary("0x75"),
  hex2binary("0x87"),
  hex2binary("0x66")
);
