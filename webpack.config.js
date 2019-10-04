const webpack = require("webpack");
const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const outputDir = path.join(__dirname, "dist/");
const Dotenv = require("dotenv-webpack");

const isProd = process.env.NODE_ENV === "production";

module.exports = {
  mode: isProd ? "production" : "development",
  output: {
    path: outputDir,
    filename: "index.[hash].js",
    publicPath: "/"
  },
  plugins: [
    new Dotenv(),
    new HtmlWebpackPlugin({
      template: "public/index.html"
    }),
    new webpack.DefinePlugin({
      "process.env.WOD_VERSION": JSON.stringify(
        require("./package.json").version
      )
    })
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 3000,
    historyApiFallback: true,
    stats: "minimal"
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          "style-loader",
          { loader: "css-loader", options: { importLoaders: 1 } },
          "postcss-loader"
        ]
      }
    ]
  }
};
