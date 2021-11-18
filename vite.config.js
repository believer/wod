import { defineConfig } from 'vite'
import reactRefresh from '@vitejs/plugin-react-refresh'

export default defineConfig({
  server: {
    port: 3000,
  },
  plugins: [reactRefresh()],
})
