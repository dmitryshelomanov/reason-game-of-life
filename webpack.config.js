const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");

module.exports = {
  entry: "./lib/js/src/Index.bs.js",
  output: {
    filename: "app.js",
    path: path.resolve(__dirname, "dist")
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: "Game of Live",
      template: "index.html"
    })
  ],
  devServer: {
    port: 9000
  }
};
