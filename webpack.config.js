module.exports = {
  mode: 'development',
  entry: './src/Demo.bs.js',
  output: {
    path: __dirname +'/public',
    filename: 'bundle.js',
  },
  devServer: {
    contentBase: './public'
  },
};