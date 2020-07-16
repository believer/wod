module.exports = {
  purge: ["./lib/**/*.js", "./src/index.css"],
  theme: {
    extend: {},
  },
  variants: {
    backgroundColor: ["responsive", "focus-within", "hover", "focus"],
    borderColor: ["responsive", "focus-within", "hover", "focus"],
    margin: ["responsive", "last"],
    textColor: ["responsive", "focus-within", "hover", "focus"],
  },
  plugins: [],
};
