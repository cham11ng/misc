function eachWithIdx(iterable, f) {
  var i = iterable.iterator();
  var idx = 0;
  while (i.hasNext()) f(i.next(), idx++);
}

function mapEach(iterable, f) {
  var vs = [];
  eachWithIdx(iterable, function (i) {
    vs.push(f(i));
  });
  return vs;
}

function escape(str) {
  str = str.replaceAll('\t|\b|\\f', '');
  str = com.intellij.openapi.util.text.StringUtil.escapeXml(str);
  str = str.replaceAll('\\r|\\n|\\r\\n', '<br/>');

  return str;
}

var NEWLINE = '\n';
var BORDER = '-----';

function output() {
  for (var i = 0; i < arguments.length; i++) {
    OUT.append(arguments[i]);
  }
}

var ValueType = {
  COLUMN: 1,
  BORDER: 2
};

function outputRow(items, type) {
  var value;
  var delimiter = ' | ';
  var left_delimiter = '| ';
  var right_delimiter = ' |';

  switch (type) {
    case ValueType.COLUMN:
      value = 'Description';
      break;

    case ValueType.BORDER:
      value = BORDER;
      break;

    default:
      value = ' ';
  }

  items = items.concat(value);
  output(left_delimiter);
  output(items.join(delimiter));
  output(right_delimiter);
  output(NEWLINE);
}

if (TRANSPOSED) {
  var values = mapEach(COLUMNS, function (col) {
    return [col.name()];
  });

  eachWithIdx(ROWS, function (row) {
    eachWithIdx(COLUMNS, function (col, i) {
      values[i].push(FORMATTER.format(row, col));
    });
  });

  eachWithIdx(COLUMNS, function (_, i) {
    outputRow(values[i]);
  });
} else {
  outputRow(
    mapEach(COLUMNS, function (col) {
      return col.name();
    }),
    ValueType.COLUMN
  );

  outputRow(
    mapEach(COLUMNS, function () {
      return BORDER;
    }),
    ValueType.BORDER
  );

  eachWithIdx(ROWS, function (row) {
    outputRow(
      mapEach(COLUMNS, function (col) {
        return FORMATTER.format(row, col);
      })
    );
  });
}
